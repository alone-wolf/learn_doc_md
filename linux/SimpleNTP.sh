#!/bin/bash

do_start()
{
    nohup python3 /root/SimpleNTP/main.py >  /dev/null 2>&1 &
}

do_stop()
{
    pkill -f /root/SimpleNTP/main.py
}

do_restart()
{
    do_stop
    sleep 1
    do_start
}

case "$1" in
    start)
        do_start
        ;;
    stop)
        do_stop
        ;;
    status)
        exit $?
        ;;
    reload)
        echo "reload"
        ;;
    restart)
        do_restart
        ;;
    *)
        echo "Usage: {start|stop|restart|reload}" >&2
        exit 3
        ;;
esac
exit 0


# after that we should have a test on this script and then
# put this file into /etc/init.d
# use downward script to register service
# update-rc.d FILE_NAME defaults
# use downward script to use service
# service FILE_NAME start
