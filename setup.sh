#!/bin/bash
# This script sets up the environment for the project.


#install nodejs
if ! command -v node &> /dev/null
then
    echo "Node.js could not be found, installing..."
    sudo apt-get install -y nodejs
else
    echo "Node.js is already installed."
fi

# install mosquitto mqtt broker

if ! command -v mosquitto &> /dev/null
then
    echo "Mosquitto MQTT broker could not be found, installing..."
    sudo apt-get install -y mosquitto mosquitto-clients
    sudo systemctl enable mosquitto
    sudo systemctl start mosquitto
else
    echo "Mosquitto MQTT broker is already installed."
fi

# Configure mosquitto
echo "Configuring Mosquitto MQTT broker..."
sudo tee /etc/mosquitto/mosquitto.conf > /dev/null <<'EOF'
# Place your local configuration in /etc/mosquitto/conf.d/
#
# A full description of the configuration file is at
# /usr/share/doc/mosquitto/examples/mosquitto.conf.example

pid_file /run/mosquitto/mosquitto.pid

persistence true
persistence_location /var/lib/mosquitto/

log_dest file /var/log/mosquitto/mosquitto.log

include_dir /etc/mosquitto/conf.d

allow_anonymous true
listener 1883 0.0.0.0

# WebSocket
listener 9001 0.0.0.0
protocol websockets
allow_anonymous true
EOF

sudo systemctl restart mosquitto
echo "Mosquitto configuration updated."

# install libopen-cv-dev
if ! dpkg -s libopencv-dev &> /dev/null
then
    echo "libopencv-dev could not be found, installing..."
    sudo apt-get install -y libopencv-dev
    echo "libopencv-dev is already installed."
fi

# install libopen-cv-dev
if ! dpkg -s libopencv-dev &> /dev/null
then
    echo "libopencv-dev could not be found, installing..."
    sudo apt-get install -y libopencv-dev
    echo "libopencv-dev is already installed."
fi

# install paho mqtt dev library
if ! dpkg -s libpaho-mqtt-dev &> /dev/null
then
    echo "libpaho-mqtt-dev could not be found, installing..."
    sudo apt-get install -y libpaho-mqtt-dev
    echo "libpaho-mqtt-dev is already installed."
fi

# install node-red

if ! command -v node-red &> /dev/null
then
    echo "Node-RED could not be found, installing..."
    sudo npm install -g --unsafe-perm node-red
    sudo npm install node-red-node-serialport
    
fi
echo "Node-RED is already installed."
