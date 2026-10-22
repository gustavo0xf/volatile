#!/bin/bash

if [[ "$1" == "process" ]]; then
    ps aux
elif [[ "$1" == "whoami" ]] then
    whoami
elif [[ "$1" == "id" ]] then
    id
else
    echo "[+] usage: $0 <process,whoami,id>"
fi
