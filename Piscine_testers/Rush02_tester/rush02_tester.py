import subprocess
import time  # Importamos el módulo time

# Colores ANSI para salida de terminal
RESET = "\033[0m"
BOLD = "\033[1m"
GREEN = "\033[32m"
RED = "\033[31m"
BLUE = "\033[34m"

# Configuración del programa
EXECUTABLE = "./rush-02"  # Cambiar el nombre al ejecutable de Rush02

TEST_CASES = [
    ("20", "twenty"),
    ("5", "five"),
    ("100", "one hundred"),
    ("42", "forty two"),
    ("999", "nine hundred ninety nine"),
    ("1001", "one thousand one"), 
    ("0", "zero"),
    ("15", "fifteen"),
    ("30", "thirty"),
    ("75", "seventy five"),
    ("200", "two hundred"),
    ("350", "three hundred fifty"),
    ("1234", "one thousand two hundred thirty four"),
    ("5000", "five thousand"),
    ("10000", "ten thousand"),
    ("100000", "one hundred thousand"),
    ("1000000", "one million"),
    ("1000000000", "one billion"),
    ("9999999", "nine million nine hundred ninety nine thousand nine hundred ninety nine"),
]

# Función para ejecutar pruebas
def run_tests():
    print("Ejecutando pruebas...")
    for idx, (input_data, expected_output) in enumerate(TEST_CASES):
        try:
            # Ejecutar el programa
            process = subprocess.run(
                [EXECUTABLE, input_data],
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
            )
            output = process.stdout
            if output == expected_output:
                print(f"\nPrueba {idx + 1}: ✅ OK")
            else:
                print(f"\nPrueba {idx + 1}: ❌ KO")
            
            # Mostrar resultados esperados y obtenidos
            print(f"Entrada: {input_data}")
            print(f"Esperado:\n{expected_output}")
            print(f"Obtenido:\n{output}")
        except Exception as e:
            print(f"\nPrueba {idx + 1}: ❌ Error de ejecución - {e}")

# Comprobación de fugas con valgrind
def check_memory_leaks():
    print("Comprobando fugas de memoria con valgrind...")
    for idx, (input_data, _) in enumerate(TEST_CASES):
        try:
            valgrind_result = subprocess.run(
                ["valgrind", "--leak-check=full", "--error-exitcode=1", EXECUTABLE, input_data],
                stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True
            )
            if valgrind_result.returncode == 0:
                print(f"Prueba {idx + 1} (valgrind): ✅ Sin fugas")
            else:
                print(f"Prueba {idx + 1} (valgrind): ❌ Fugas detectadas")
                print(valgrind_result.stderr)
        except Exception as e:
            print(f"Prueba {idx + 1} (valgrind): ❌ Error de ejecución - {e}")

# Main
if __name__ == "__main__":
    # Mostrar mensaje 'rush 02' durante 3 segundos
    print(GREEN + BOLD + """
	

██████╗ ██╗   ██╗███████╗██╗  ██╗         ██████╗ ██████╗     ████████╗███████╗███████╗████████╗███████╗██████╗ 
██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔═████╗╚════██╗    ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝██╔════╝██╔══██╗
██████╔╝██║   ██║███████╗███████║        ██║██╔██║ █████╔╝       ██║   █████╗  ███████╗   ██║   █████╗  ██████╔╝
██╔══██╗██║   ██║╚════██║██╔══██║        ████╔╝██║██╔═══╝        ██║   ██╔══╝  ╚════██║   ██║   ██╔══╝  ██╔══██╗
██║  ██║╚██████╔╝███████║██║  ██║███████╗╚██████╔╝███████╗       ██║   ███████╗███████║   ██║   ███████╗██║  ██║
╚═╝  ╚═╝ ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚══════╝       ╚═╝   ╚══════╝╚══════╝   ╚═╝   ╚══════╝╚═╝  ╚═╝
                                                                                                            
                                         2024/11/12 - ismherna@student.42.fr - 42 Madrid - Ismael Hernández                                                    

	""" + RESET)
    time.sleep(1)  # Esperar 1 segundo

    mode = input(GREEN + BOLD +"Options:\n(1: Ejecutar pruebas, 2: Ejecutar pruebas con valgrind)\n\n"+ RESET).strip()
    if mode == "1":
        run_tests()
    elif mode == "2":
        run_tests()
        check_memory_leaks()
    else:
        print("Opción no válida.")
