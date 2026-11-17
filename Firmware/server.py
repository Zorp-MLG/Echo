import asyncio
import websockets
import json
import time

class ActionEngine:
    def __init__(self, ws_manager):
        self.ws = ws_manager
        self.connected_devices = {}
        self.pending_actions = {}

    async def execute(self, action_name, params, requester="AI"):
        action_id = f"act_{int(time.time()*1000)}"
        print(f"[Action Engine] Executing {action_name} with {params}")
        
        target_device = None
        if action_name == "FAN_SET":
            target_device = "U4_ENV"
        elif action_name == "CAMERA_MOVE":
            target_device = "U15_VOICE_SERVO"
        elif action_name in ["PC_OPEN_APPLICATION", "PC_SCREEN_CAPTURE"]:
            target_device = "PC_AGENT"
            
        if target_device not in self.connected_devices:
            return {"status": "error", "message": f"{target_device} not connected"}

        msg = {
            "type": "action_command",
            "payload": {
                "id": action_id,
                "action": action_name,
                "params": params
            }
        }
        
        await self.connected_devices[target_device].send(json.dumps(msg))
        
        self.pending_actions[action_id] = asyncio.Future()
        try:
            result = await asyncio.wait_for(self.pending_actions[action_id], timeout=5.0)
            return {"status": "success", "action_id": action_id}
        except asyncio.TimeoutError:
            return {"status": "timeout", "action_id": action_id}

class SensorEngine:
    def __init__(self):
        self.history = []

    def process_reading(self, device_id, payload):
        payload["device_id"] = device_id
        payload["server_time"] = time.time()
        self.history.append(payload)
        
        if len(self.history) > 100:
            self.history.pop(0)

        if "pm25" in payload and payload["pm25"] > 50:
            return "WARNING: High PM2.5 detected. Suggesting fan activation."
        if "temp_c" in payload and payload["temp_c"] > 35:
            return "WARNING: High temperature detected."
        return None

connected_clients = {}
action_engine = None
sensor_engine = SensorEngine()

async def handler(websocket):
    global action_engine
    try:
        async for message in websocket:
            data = json.loads(message)
            
            if data["type"] == "register":
                device_id = data["device_id"]
                connected_clients[device_id] = websocket
                print(f"[Server] Device Connected: {device_id}")
                
            elif data["type"] == "sensor_update":
                alert = sensor_engine.process_reading(data["device_id"], data["payload"])
                if alert:
                    print(f"[Sensor AI] {alert}")
                    
            elif data["type"] == "action_status":
                action_id = data["payload"]["action_id"]
                if action_id in action_engine.pending_actions:
                    action_engine.pending_actions[action_id].set_result(data["payload"]["status"])
                    
    except websockets.exceptions.ConnectionClosed:
        pass
    finally:
        for dev, ws in list(connected_clients.items()):
            if ws == websocket:
                del connected_clients[dev]
                print(f"[Server] Device Disconnected: {dev}")

async def main():
    global action_engine
    action_engine = ActionEngine(connected_clients)
    
    print("[Server] Starting Echo Central Server on ws://0.0.0.0:8080")
    async with websockets.serve(handler, "0.0.0.0", 8080):
        async def simulate_ai():
            await asyncio.sleep(10)
            print("[AI] Decided to turn on Fan 1 due to simulated sensor reading.")
            await action_engine.execute("FAN_SET", {"fan_id": 1, "state": True})
            
        asyncio.create_task(simulate_ai())
        await asyncio.Future()

if __name__ == "__main__":
    asyncio.run(main())
