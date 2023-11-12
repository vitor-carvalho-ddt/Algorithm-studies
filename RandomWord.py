import random
from random import randrange

def s_of_n_initializer(n):
    sample = []
    counter = 0
    def s_of_n(item):
        nonlocal counter

        if item < n:
            sample.append(item)
        elif randrange(counter) < n:
            sample[randrange(n)] = item

        counter += 1
        return sample
    return s_of_n


def main():
    bin = [0]* 10
    n = 3 ## FOR THE EXAMPLE ASKED IN THE QUESTION, JUST REPLACE 3 WITH 1, TO HAVE A SAMPLE OF 1 ELEMENT
    m = 10
    s_of_n = s_of_n_initializer(n)
    for i in range(m):
        sample = s_of_n(item=i)
        print(f"Sample: {sample}")

    print("################################")

    for trial in range(100000):        
        s_of_n = s_of_n_initializer(n)

        for i in range(m):
            sample = s_of_n(item=i)
        
        for s in sample:
            bin[s] += 1

    print("\nTest item frequencies for 100000 runs:\n ",
          '\n  '.join("%i:%i" % x for x in enumerate(bin)))
    
if __name__ == "__main__":
    main()