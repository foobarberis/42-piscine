#!/bin/sh
ifconfig -a | grep -w 'ether' | awk '{print $2}'
