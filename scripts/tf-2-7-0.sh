sudo apt-get update
sudo apt-get install -y python3-pip pkg-config
sudo apt-get install -y libhdf5-serial-dev hdf5-tools libhdf5-dev zlib1g-dev zip libjpeg8-dev liblapack-dev libblas-dev gfortran
sudo pip3 install -U testresources setuptools
sudo ln -s /usr/include/locale.h /usr/include/xlocale.h

sudo pip3 install 'protobuf<4' 'Cython<3'
sudo pip3 install -U numpy future mock gast pybind11 packaging

git clone https://github.com/h5py/h5py.git
cd h5py
git config user.email "you@example.com"
git config user.name "Your Name"
git checkout 3.1.0
git stash
git cherry-pick 3bf862daa4ebeb2eeaf3a0491e05f5415c1818e4 #idk if u need this
H5PY_SETUP_REQUIRES=0 pip3 install . --no-deps --no-build-isolation
H5PY_SETUP_REQUIRES=0 python3 setup.py bdist_wheel

sudo pip3 install -U keras_preprocessing keras_applications
sudo wget --no-check-certificate https://developer.download.nvidia.com/compute/redist/jp/v461/tensorflow/tensorflow-2.7.0+nv22.1-cp36-cp36m-linux_aarch64.whl
sudo pip3 install --verbose tensorflow-2.7.0+nv22.1-cp36-cp36m-linux_aarch64.whl