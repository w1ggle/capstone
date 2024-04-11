#for some reason pip doesnt include the files needed to copy, so building from source
git clone https://github.com/NVIDIA/jetson-gpio.git
cd jetson-gpio

sudo python3 setup.py install

sudo groupadd -f -r gpio
sudo usermod -a -G gpio team29

sudo cp lib/python/Jetson/GPIO/99-gpio.rules /etc/udev/rules.d/
sudo udevadm control --reload-rules && sudo udevadm trigger