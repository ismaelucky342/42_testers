##### NOT FINISHED - COOMING SOON  ########

import subprocess
import sys
import time
import re

PATH_TO_CLIENT = "../client"

colors = {
    "Black": '\033[0;30m', "D_Gray": '\033[1;30m', "Red": '\033[0;31m', "L_Red": '\033[1;31m',
    "Green": '\033[0;32m', "L_Green": '\033[1;32m', "Orange": '\033[0;33m', "Yellow": '\033[1;33m',
    "Blue": '\033[0;34m', "L_Blue": '\033[1;34m', "Purple": '\033[0;35m', "L_Purple": '\033[1;35m',
    "Cyan": '\033[0;36m', "L_Cyan": '\033[1;36m', "L_Gray": '\033[0;37m', "White": '\033[1;37m',
    "NC": '\033[0m'
}

# Preparing tests
tm, tb, t1, t2, t3, t4, t5, t6, p_id = [0] * 9

for arg in sys.argv[1:]:
    if arg == '-m':
        tm = 1
    elif arg == '-b':
        tb = 1
    elif arg == '-1':
        t1 = 1
    elif arg == '-2':
        t2 = 1
    elif arg == '-3':
        t3 = 1
    elif arg == '-4':
        t4 = 1
    elif arg == '-5':
        t5 = 1
    elif arg == '-6':
        t6 = 1
    else:
        if p_id == 0:
            p_id = arg
        else:
            print("[ERROR] Please enter correct arg.")
            sys.exit(1)

if not re.match(r'^\d+$', str(p_id)):
    print("[ERROR] Please enter correct arg.")
    sys.exit(1)

# Testing

# Speed Test
print(f"{colors['L_Green']} [Speed test]\tprinting 1 000 char {colors['NC']}")
start_time = time.time()
subprocess.run([PATH_TO_CLIENT, str(p_id), "..................................................................................................."
              * 10])
print(f"Time taken: {time.time() - start_time:.2f} seconds")

# Mandatory Tests
if t1 == 1 or tm == 1:
    print(f"{colors['L_Green']} [Test 1]\tBasic test {colors['NC']}")
    subprocess.run([PATH_TO_CLIENT, str(p_id), "First test"])

if t2 == 1 or tm == 1:
    print(f"{colors['L_Green']}\n [Test 2]\tEmpty string{colors['NC']}")
    subprocess.run([PATH_TO_CLIENT, str(p_id), ""])

if t3 == 1 or tm == 1:
    print(f"{colors['L_Green']}\n [Test 3]\tSending big str {colors['NC']}")
    big_string = """




    """ * 2000  # Reduce the length here for readability
    subprocess.run([PATH_TO_CLIENT, str(p_id), big_string])

if t4 == 1 or tm == 1:
    print(f"{colors['L_Green']}\n [Test 4]\tTrying to crash your exchange Server-Client, sending str with 3 000 char (15 times) {colors['NC']}")
    crash_string = """
         
    """ * 300  # Reduce the length here for readability

    for i in range(1, 16):
        print(f"{colors['Green']} [ {i} ]{colors['NC']}")
        subprocess.run([PATH_TO_CLIENT, str(p_id), crash_string])

# Bonus Tests
if t5 == 1 or tb == 1:
    print(f"{colors['L_Green']}\n [Test 5]\tGuess the movie with emojis {colors['NC']}")
    emoji_string = """
     ⛴️  +  🌊  + 💥 = ❓
     👦 +  👽  + 🚲 = ❓
     🏰 +  ❄️   + 👭 = ❓
    """
    subprocess.run([PATH_TO_CLIENT, str(p_id), emoji_string])

if t6 == 1 or tb == 1:
    print(f"{colors['L_Green']}\n [Test 6]\tTesting the connection between server-client{colors['NC']}")
    large_string = """




    """ * 530  # Reduce the length here for readability

    for i in range(1, 11):
        print(f"{colors['L_Green']} [ {i} ]{colors['NC']}")
        subprocess.run([PATH_TO_CLIENT, str(p_id), large_string])
