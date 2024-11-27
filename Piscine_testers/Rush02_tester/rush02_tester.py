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
    ("20", "veinte\n"),
    ("5", "cinco\n"),
    ("100", "cien\n"),
    ("42", "cuarenta y dos\n"),
    ("999", "novecientos noventa y nueve\n"),
    ("1001", "Error\n"),  # Asegurando que valores fuera de rango den error
    ("0", "cero\n"),
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
                print(f"Prueba {idx + 1}: ✅ Pasó")
            else:
                print(f"Prueba {idx + 1}: ❌ Falló")
            
            # Mostrar resultados esperados y obtenidos
            print(f"Entrada: {input_data}")
            print(f"Esperado:\n{expected_output}")
            print(f"Obtenido:\n{output}")
        except Exception as e:
            print(f"Prueba {idx + 1}: ❌ Error de ejecución - {e}")

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
