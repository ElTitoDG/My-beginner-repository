#!/bin/bash


chrome_open_tab(){
    xdg-open --new -a "Google Chrome" --args $@
}

#use with firefox in ubuntu
firefox_new_tab(){
    firefox --new-tab
}


while :
do
    chrome_open_tab
    ((counter++))
    #Delete this when using
    sleep 1
done
