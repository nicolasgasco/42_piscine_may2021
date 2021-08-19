#!/bin/bash
(find . -type d  && find . -type f) | wc -l | tr -d " "
