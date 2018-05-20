#!/usr/bin/env python3

import json
import os
import random
import signal
import struct
import sys
import time

try:
    import asyncio
except ImportError:
    print("asyncio module not found (try pip install asyncio, or upgrade to Python 3.4 or later)")
    sys.exit(1)

try:
    import websockets
except ImportError:
    print("websockets module not found (try pip install websockets)")
    sys.exit(1)

async def test_get_account():
    print(" test get account...")
    login_sub = {"id":1, "method":"call", "params":[1, "login", ["",""]]}
    db_sub = {"id":2, "method":"call", "params":[1, "database", []]}
    acct_sub = {"id":3, "method":"call", "params":[2, "get_account_by_name", ["nathan"]]}
    async with websockets.connect('ws://localhost:8090/') as ws:
        print("ws sent ", login_sub)
        await ws.send(json.dumps(login_sub))
        print("ws sent ", db_sub)
        await ws.send(json.dumps(db_sub))
        print("ws sent ", acct_sub)
        await ws.send(json.dumps(acct_sub))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
    ws.close()

print("start web socket api tests")
asyncio.get_event_loop().run_until_complete(test_get_account())
print("test finished")
