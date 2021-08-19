#!/bin/bash
echo $FT_NBR1 + $FT_NBR2 | tr "'" "0" | tr "\\" "1" | tr "?" "3" | tr "\"" "2" | tr "\!" "4" | tr "mrdoc" "01234" | tr "0123456789ABC" "gtaio luSnemf" | tr -d " + "
