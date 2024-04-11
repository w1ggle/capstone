systemctl stop nvgetty
systemctl disable nvgetty
udevadm trigger
sudo apt-get install python3-serial