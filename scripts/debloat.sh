# combination of the below
# https://gist.github.com/NickSeagull/ed43a80db6a54d69ded3e18f8babaf19
# https://gist.github.com/adujardin/c0ee25cfb343ea5b6d17ea88ec6634ac

## Step 1, safe
sudo apt update
sudo apt clean
sudo apt remove thunderbird libreoffice-* -y
sudo apt-get remove                   \
aisleriot                             \
brltty                                \
duplicity                             \
empathy                               \
empathy-common                        \
example-content                       \
gnome-accessibility-themes            \
gnome-contacts                        \
gnome-mahjongg                        \
gnome-mines                           \
gnome-orca                            \
gnome-screensaver                     \
gnome-sudoku                          \
gnome-video-effects                   \
landscape-common                      \
libsane                               \
libsane-common                        \
python3-uno                           \
rhythmbox                             \
rhythmbox-plugins                     \
rhythmbox-plugin-zeitgeist            \
sane-utils                            \
shotwell                              \
shotwell-common                       \
telepathy-gabble                      \
telepathy-haze                        \
telepathy-idle                        \
telepathy-indicator                   \
telepathy-logger                      \
telepathy-mission-control-5           \
telepathy-salut                       \
totem                                 \
totem-common                          \
totem-plugins                         \
printer-driver-brlaser                \
printer-driver-foo2zjs                \
printer-driver-foo2zjs-common         \
printer-driver-m2300w                 \
printer-driver-ptouch                 \
printer-driver-splix -y

## Step 2, still safe but not recommended for dev use
# samples
sudo rm -rf /usr/local/cuda/samples \
    /usr/src/cudnn_samples_* \
    /usr/src/tensorrt/data \
    /usr/src/tensorrt/samples \
    /usr/share/visionworks* ~/VisionWorks-SFM*Samples \
    /opt/nvidia/deepstream/deepstream*/samples	

sudo apt update && sudo apt upgrade -y