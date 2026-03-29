import math

def calculate_thermodynamics():
    print("Process: ")
    print("1) Isochoric")
    print("2) Isobaric")
    print("3) Isothermal")
    print("4) Adiabatic")
    
    choice = input("Enter your choice (1-4): ")
    
    gases = {
        'air': {'R': 287.05, 'i': 5, 'mu': 0.029},
        'O2':  {'R': 259.9, 'i': 5, 'mu': 0.032},
        'N2':  {'R': 296.7, 'i': 5, 'mu': 0.028},
        'CO2': {'R': 188.9, 'i': 6, 'mu': 0.044}
    }
    
    gas_type = input("Enter gas type (air, O2, N2, CO2): ")
    gas = gases.get(gas_type, gases['air'])
    
    m = float(input("Mass (m), kg: "))
    t1 = float(input("Initial temperature (t1), °C: "))
    
    # Standard constants calculation
    T1 = t1 + 273.15
    R, i = gas['R'], gas['i']
    cv = (i/2) * R           # Specific heat capacity at constant volume
    cp = ((i+2)/2) * R       # Specific heat capacity at constant pressure
    k = (i+2)/i              # Adiabatic index (gamma)
    
    print("\n--- Results ---")

    if choice == '1': # Isochoric - Problems 7, 8
        t2 = float(input("Final temperature (t2), °C: "))
        T2 = t2 + 273.15
        Q = m * cv * (T2 - T1)
        W = 0
        dU = Q
        dS = m * cv * math.log(T2/T1)
        print(f"Heat (Q): {Q/1000:.2f} kJ")
        print(f"Work (W): 0 kJ")
        print(f"Internal Energy change (ΔU): {dU/1000:.2f} kJ")
        print(f"Entropy change (ΔS): {dS:.4f} J/K")

    elif choice == '2': # Isobaric - Problems 9, 10
        t2 = float(input("Final temperature (t2), °C: "))
        T2 = t2 + 273.15
        Q = m * cp * (T2 - T1)
        W = m * R * (T2 - T1)
        dU = m * cv * (T2 - T1)
        dS = m * cp * math.log(T2/T1)
        print(f"Heat (Q): {Q/1000:.2f} kJ")
        print(f"Work (W): {W/1000:.2f} kJ")
        print(f"Internal Energy change (ΔU): {dU/1000:.2f} kJ")
        print(f"Entropy change (ΔS): {dS:.4f} J/K")

    elif choice == '3': # Isothermal - Problem 11
        p1 = float(input("Initial pressure (P1), bar: "))
        p2 = float(input("Final pressure (P2), bar: "))
        W = m * R * T1 * math.log(p1/p2)
        Q = W
        dU = 0
        dS = m * R * math.log(p1/p2)
        print(f"Heat (Q) = Work (W): {W/1000:.2f} kJ")
        print(f"Internal Energy change (ΔU): 0 kJ")
        print(f"Entropy change (ΔS): {dS:.4f} J/K")

    elif choice == '4': # Adiabatic - Problem 12
        p1 = float(input("Initial pressure (P1), bar: "))
        p2 = float(input("Final pressure (P2), bar: "))
        T2 = T1 * (p2/p1)**((k-1)/k)
        W = m * R * (T1 - T2) / (k - 1)
        dU = -W
        print(f"Final temperature (t2): {T2 - 273.15:.2f} °C")
        print(f"Heat (Q): 0 kJ")
        print(f"Work (W): {W/1000:.2f} kJ")
        print(f"Internal Energy change (ΔU): {dU/1000:.2f} kJ")
        print(f"Entropy change (ΔS): 0 J/K (Isentropic process)")

if __name__ == "__main__":
    calculate_thermodynamics()