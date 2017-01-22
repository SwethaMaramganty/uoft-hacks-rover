@echo off
echo Starting image processing on "image.jpeg"
python save_image.py

ping -n 2 127.0.0.1 >nul

echo Downloaded image from Stream

java get_color

pause