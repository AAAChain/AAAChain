AAA Chain
==============

AAA Chain is the customized blockchain implementation based on Bitshare2.0 for data area scenario.
Import new object type to support data creation and transacton.
Migrate webassembly VM into AAA chain to provide contract.


Build from source
--------------------------


Build on Ubuntu 16.04 LTS, and the build dependencies may be installed with:

    sudo apt-get update
    sudo apt-get install autoconf cmake git libboost-all-dev libssl-dev g++ libcurl4-openssl-dev

To build after all dependencies are installed:

    git clone https://github.com/AAAChain/aaa_chain.git
    cd aaa_chain
    git checkout <LATEST_RELEASE_TAG>
    git submodule update --init --recursive
    cmake -DCMAKE_BUILD_TYPE=Release .
    make

**NOTE:** AAA Chain requires a [Boost](http://www.boost.org/) version in the range [1.57, 1.63]. 

Start witness node
------------------

After building, launch the witness node with the following command:

    ./programs/witness_node/witness_node  --rpc-endpoint="127.0.0.1:8090"

The node will consume some time to sync data from the chain.

Start commandline wallet
------------------------

After starting the witness node, start commandline wallet in a separate terminal by running:

    ./programs/cli_wallet/cli_wallet --server-rpc-endpoint=ws://127.0.0.1:8090

Set your inital password:

    >>> set_password <PASSWORD>
    >>> unlock <PASSWORD>

To import your initial balance:

    >>> import_balance <ACCOUNT NAME> [<WIF_KEY>] true

If you send private keys over this connection, `rpc-endpoint` should be bound to localhost for security.

Use `help` to see all available wallet commands. Source definition and listing of all commands is available
[here](/libraries/wallet/include/graphene/wallet/wallet.hpp).

Support
-------

bugs can be reported to the [issue tracker](https://github.com/AAAChain/aaa_chain/issues).
