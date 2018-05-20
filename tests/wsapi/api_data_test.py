#!/usr/bin/env python3

import json
import os
import random
import signal
import struct
import sys
import time
import datetime

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

async def test_create():
    print(" create test start...")

    today = datetime.datetime.now()
    dd = today + datetime.timedelta(minutes=10)
    ts = dd.strftime("%Y-%m-%dT%H:%M:%S")

    db_sub = {"id":1, "method":"call", "params":[1, "database", []]}
    net_sub = {"id":2, "method":"call", "params":[1, "network_broadcast", []]}

    update_sub = {"id":3, "method":"call", "params":[3, "broadcast_transaction_with_callback",[13,{"ref_block_num":5382,"ref_block_prefix":4088778371,"expiration":ts,"operations":[[48,{"fee":{"amount":"0","asset_id":"1.3.0"},"ownerId":"1.2.4","url":"test","data_desc":"test","data_hash":0,"data_key":0,"data_size":8,"active":{"weight_threshold":1,"account_auths":[],"key_auths":[["AAA6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",1]],"address_auths":[]},"options":{},"extensions":[]}]],"extensions":[]}]]} 

    create_sub = {"id":3, "method":"call", "params":[3, "broadcast_transaction_with_callback",[13,{"ref_block_num":5382,"ref_block_prefix":4088778371,"expiration":ts,"operations":[[47,{"fee":{"amount":"0","asset_id":"1.3.0"},"ownerId":"1.2.4","url":"test","data_desc":"test","data_hash":0,"data_key":0,"data_size":8,"active":{"weight_threshold":1,"account_auths":[],"key_auths":[["AAA6MRyAjQq8ud7hVNYcfnVPJqcVpscN5So8BhtHuGYqET5GDW5CV",1]],"address_auths":[]},"options":{},"extensions":[]}]],"extensions":[]}]]} 


    async with websockets.connect('ws://localhost:8090/') as ws:
        await ws.send(json.dumps(db_sub))
        await ws.send(json.dumps(net_sub))
        await ws.send(json.dumps(create_sub))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
    ws.close()

async def test_get_data():
    print(" test get account...")
    login_sub = {"id":1, "method":"call", "params":[1, "login", ["",""]]}
    db_sub = {"id":2, "method":"call", "params":[1, "database", []]}

    #need to give params: 2 to call database api
    data_sub = {"id":3, "method":"call", "params":[2, "get_data_assets", [["1.16.1"]]]}
    async with websockets.connect('ws://localhost:8090/') as ws:
        print("ws sent ", login_sub)
        await ws.send(json.dumps(login_sub))
        print("ws sent ", db_sub)
        await ws.send(json.dumps(db_sub))
        print("ws sent ", data_sub)
        await ws.send(json.dumps(data_sub))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
        result = await ws.recv()
        print("< {}".format(result))
    ws.close()

print("start web socket api tests")
asyncio.get_event_loop().run_until_complete(test_get_data())
asyncio.get_event_loop().run_until_complete(test_create())
print("test finished")
