#!/bin/bash
# set up virtual environment manually
source compile
mv adversary.so ../app
cd ../app
export FLASK_APP=app
export FLASK_DEBUG=true
python -m flask run
