#!/bin/bash

# 1) Create a new directory called rover_mission and navigate into it.
mkdir -p rover_mission
cd rover_mission || exit

# 2) Create three empty files: log1.txt, log2.txt, log3.txt
touch log1.txt log2.txt log3.txt

# 3) Rename log1.txt to mission_log.txt
mv log1.txt mission_log.txt

# 4) Find all files in the current directory that have a .log extension
echo "Files with .log extension in the current directory:"
find . -type f -name "*.log"

# 5) Display contents of mission_log.txt without opening it in an editor
echo "Displaying contents of mission_log.txt:"
cat mission_log.txt

# 6) Find and display lines containing the word "ERROR" in mission_log.txt
echo "Searching for lines containing 'ERROR' in mission_log.txt:"
grep "ERROR" mission_log.txt

# 7) Count the number of lines in mission_log.txt
echo "Counting lines in mission_log.txt:"
wc -l < mission_log.txt

# 8) Show system's current date and time
echo "Current system date and time:"
date

# 9) Display CPU usage in real-time (static snapshot for script use)
echo "CPU usage snapshot:"
top -n 1 -b | head -20

# 10) Schedule a system shutdown in 10 minutes
echo "Scheduling system shutdown in 10 minutes..."
sudo shutdown +10 "System will shut down in 10 minutes."

echo "Script execution complete."