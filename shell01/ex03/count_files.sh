#!/bin/sh
(find . -type f && find . -type d) | wc -l | tr -d ' '
