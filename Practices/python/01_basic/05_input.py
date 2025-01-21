###
# 05 - Entrada de usuario (input()) - Versión simplificada
# La función input() permite obtener datos del usuario a través de la consola
###

nombre = input("Hola, como te llamas?\n")
print(f"Hola {nombre}. encantado de conocerte")

age = int(input("Cuantos años tienes: \n"))
print(f"Tienes {age} años")

print("Obtener múltiples valores a la vez")
country, city = input("¿En qué país y ciudad vives?\n").split()

print(f"Vives en {country}, {city}")