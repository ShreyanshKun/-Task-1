#!/bin/bash

# rover_system_check.sh

# Generate a random battery percentage between 0 and 100
battery=$((RANDOM % 101))

# Log the battery status
echo "Battery level: $battery%"

# Check if battery is below critical level (20%)
if [ "$battery" -lt 20 ]; then
    echo " Battery low! Return to base!"
    exit 1
fi

# Test network connectivity by pinging google.com
ping -c 1 -W 2 google.com > /dev/null 2>&1

# Check if ping was successful
if [ $? -ne 0 ]; then
    echo "Communication failure!"
    exit 1
fi

# If everything passes
echo "All systems operational!"