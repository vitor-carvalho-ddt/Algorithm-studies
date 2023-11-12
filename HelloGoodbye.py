def main():
    names = []
    names.append(input("Please, provide the first name:"))
    names.append(input("Please, provide the second name:"))

    print(f"Hello {names[0]} and {names[1]}")
    print(f"Hello {names[1]} and {names[0]}")


if __name__ == "__main__":
    main()