#echo "Input the demo you want"
#echo "cs : can setting, ct : can test, ci : can interpreter test"
#echo "ce : [5. can interpreter execute], cf : candata file save"

#Per default, CAN-6 is routed to can0 SocketCAN interface on TegraA and CAN-6 to can1 SocketCAN interface on TegraB.


echo "[4] CAN SETTING: cs	[4-1] CAN rx TEST: ct	[4-2] CAN tx TEST: cx"
echo "[CAN Test]
(1)CAN Interpreter TEST: ci	(2)CAN Data File Save: cf"
echo "[1] CAN ACC TX: cc    [can tx test: cx"
echo "[1] : c1    [2]: c2"
echo "[3] : c3    [4]: c4"
echo "[5] : c5    [6]: c6"


echo -n "demo :"
read su

cd /usr/local/driveworks-0.6/bin

if [ "$su" = "cs" ]; then
    echo "can setting"
    sudo ip link set can0 type can bitrate 500000
    sudo ip link set can0 up
elif [ "$su" = "ct" ]; then
    echo "can rx test"
    ./sample_canbus_logger --driver=can.socket --params=device=can0
elif [ "$su" = "cx" ]; then
    echo "can tx test"
    ./sample_canbus_logger --send_i_understand_implications=100 --driver=can.socket --params=device=can0
elif [ "$su" = "ci" ]; then
    echo "can interpret"
    ./sample_canbusinterpreter --driver=can.socket --params=device=can0
elif [ "$su" = "cc" ]; then
    echo "can AEB test execute"
    ./canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "c1" ]; then
    echo "can AEB test execute"
    ./c01_canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "c2" ]; then
    echo "can AEB test execute"
    ./fescaro_canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "c3" ]; then
    echo "can AEB test execute"
    ./C21_canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "c4" ]; then
    echo "can AEB test execute"
    ./canbus_acctest_c3 --driver=can.socket --params=device=can0 
elif [ "$su" = "c5" ]; then
    echo "can AEB test execute"
    ./c41_canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "c6" ]; then
    echo "can AEB test execute"
    ./c51_canbus_acctest --driver=can.socket --params=device=can0 
elif [ "$su" = "cf" ]; then
    echo "candata file save"
    ./sample_record --can-driver=can.socket --can-params=device=can0 --write-file-can=/home/nvidia/Documents/0518/can.bin

else
    echo "invalid argument."

fi

