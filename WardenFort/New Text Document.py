import asyncio
import websockets
import json

connected_clients = set()

async def handle_connection(websocket, path):
    print(f"New connection from {websocket.remote_address}")
    connected_clients.add(websocket)
    try:
        async for message in websocket:
            print(f"Message received: {message}")
            data = json.loads(message)
            if data['type'] == 'message':
                response = json.dumps({
                    'type': 'message',
                    'content': f"Server received: {data['content']}"
                })
                for client in connected_clients:
                    if client != websocket:
                        await client.send(response)
    except websockets.ConnectionClosed:
        print(f"Connection closed: {websocket.remote_address}")
    finally:
        connected_clients.remove(websocket)

start_server = websockets.serve(handle_connection, "localhost", 12345)

print("WebSocket server started on ws://localhost:12345")
asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
