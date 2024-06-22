#!/bin/bash

PORT="4456"

for i in {1..10}
do
    (echo -en "team_1\n"; sleep 1; cat /dev/random; sleep 20) | nc 127.0.0.1 $PORT &
done

wait
echo "All connections attempted."
