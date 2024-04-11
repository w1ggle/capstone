systemctl stop nvgetty
systemctl disable nvgetty
udevadm trigger
sudo apt-get install python3-serial

#show all uart ports afterwards
ls -l /dev/ttyS* /dev/ttyTHS*