#!/bin/sh

DEVICE_TTY=/dev/ttyS6

stty -F ${DEVICE_TTY} 115200

echo ATE0 | socat - ${DEVICE_TTY},crnl > /dev/null 2> /dev/null

at_command() {
    local atcmd=$1
    read -t2 -d '' resp < <(echo $atcmd | socat - ${DEVICE_TTY},crnl | grep "[A-Za-z0-9]" | sed -e 's/\s*//' 2> /dev/null)
    echo "$atcmd -> $resp"
}

reset_modem() {
    logger -t 90_configure_cell "Resetting Modem..."
    gpioset --mode=time --sec=4 `gpiofind PD7`=1 ; gpioset `gpiofind PD7`=0
    sleep 10
    killall socat
}

init_modem() {
    at_command "AT" 
    cntlim=0

    # clear the AT command channel of any buffered responses
    while read -t1 garbage < /dev/ttyUSB2 ; 
    do 
            garbage="" 
            cntlim=$((cntlim + 1))

        if [ $cntlim -eq 50 ] ; then
                    echo "AT" > ${DEVICE_TTY}
            fi
            if [ $cntlim -eq 100 ] ; then
                    logger -t bg95 "resetting modem..."
                    reset_modem
            fi
            if [ $cntlim -gt 200 ] ; then
                    logger -t bg95 "cannot communicate with modem."
                    exit 1
        fi

    done;

    at_command "AT"
    echo resp: $resp
    if [ "$resp" != "OK" ] ; then
        reset_modem
    fi
}

