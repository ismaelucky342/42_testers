import os
import subprocess
from tools import set_size, all_combinations, generate_sequence, generate_random_sequence, check_moves

def run_push_swap(var):
    command = f"../push_swap {var} > .moves"
    exit_status = subprocess.call(command, shell=True)

    moves_count = subprocess.check_output("wc -l < .moves", shell=True).decode().strip()

    checker_command = f"cat .moves | ./srcs/checker_linux {var}"
    checker_output = subprocess.check_output(checker_command, shell=True).decode().strip()

    os.remove('.moves')

    return moves_count, checker_output, exit_status

def main_tester(system_type):
    file_path = '.results'
    with open(file_path, 'w') as file:
        for x in [1, 2, 3, 4, 5, 100, 500]:
            if x == 100 or x == 500:
                print("\033[0;36mInput size\tMoves\tChecker\tResult\033[0m")
            else:
                print("\033[0;36mInput\t\tMoves\tChecker\tResult\033[0m")

            rep = set_size(x)
            if x < 100:
                for combination in all_combinations(x):
                    var = ' '.join(map(str, combination))
                    if x < 4:
                        print(f"[{var}]\t\t", end="")
                    else:
                        print(f"[{var}]\t", end="")

                    moves_count, checker_output, exit_status = run_push_swap(var)
                    print(f"{moves_count}\t", end="")
                    file.write(f"{x} - {moves_count}\n")

                    if checker_output == "OK":
                        print("\033[1;32mOK\033[0m", end="")
                    else:
                        print("\033[1;31mKO\033[0m", end="")
                    
                    check_moves(x, moves_count, checker_output, exit_status)
                    print()  # Nueva línea después de cada caso
            else:
                first_iteration = True
                for _ in range(rep):
                    if first_iteration:
                        var = ' '.join(map(str, generate_sequence(x)))
                        first_iteration = False
                    else:
                        var = ' '.join(map(str, generate_random_sequence(x)))

                    if x in [1, 2, 3, 4, 5]:
                        print(f"[{var}]\t\t", end="")
                    elif x in [100, 500]:
                        print(f"{x}\t\t", end="")
                    else:
                        print(f"[{var}]\t", end="")

                    moves_count, checker_output, exit_status = run_push_swap(var)
                    print(f"{moves_count}\t", end="")
                    if exit_status == 139:
                        moves_count = "Segmentation Fault"
                    file.write(f"{x} - {moves_count}\n")

                    if checker_output == "OK":
                        print("\033[1;32mOK\033[0m", end="")
                    else:
                        print("\033[1;31mKO\033[0m", end="")

                    check_moves(x, moves_count, checker_output, exit_status)
                    print()  # Nueva línea después de cada caso

if __name__ == "__main__":
    system_type = "linux"  # Puedes cambiar esto según el sistema
    main_tester(system_type)
