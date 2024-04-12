sudo apt-get update
sudo apt-get install -y python3-pip pkg-config pkgconfig
sudo apt-get install -y libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
sudo pip3 install -U testresources setuptools
sudo ln -s /usr/include/locale.h /usr/include/xlocale.h

sudo pip3 install 'protobuf<4' 'Cython<3'
sudo pip3 install -U numpy future mock gast pybind11 packaging

sudo pip3 install -U keras_preprocessing keras_applications
sudo wget --no-check-certificate https://developer.download.nvidia.com/compute/redist/jp/v461/tensorflow/tensorflow-1.15.5+nv22.1-cp36-cp36m-linux_aarch64.whl
sudo pip3 install --verbose tensorflow-1.15.5+nv22.1-cp36-cp36m-linux_aarch64.whl
