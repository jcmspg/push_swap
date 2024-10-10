import random

def generate_random_numbers(size, max_value):
    """Generate a list of random integers, with possible duplicates."""
    return [random.randint(0, max_value) for _ in range(size)]

def check_for_duplicates(numbers):
    """Check for duplicates in the list of numbers."""
    seen = set()
    duplicates = set()
    
    for number in numbers:
        if number in seen:
            duplicates.add(number)
        else:
            seen.add(number)

    return duplicates

def save_to_file(numbers, filename):
    """Save numbers to a text file, separated by spaces."""
    with open(filename, 'w') as f:
        f.write(' '.join(map(str, numbers)))

def main():
    # Settings
    size = 10000          # Total number of integers to generate
    max_value = 500221     # Maximum value for the integers
    filename = 'random_numbers.txt'  # Output file name

    # Generate random numbers
    random_numbers = generate_random_numbers(size, max_value)
    
    # Check for duplicates
    duplicates = check_for_duplicates(random_numbers)

    # Save to file
    save_to_file(random_numbers, filename)

    # Print results
    print(f"Generated {size} random numbers (values between 0 and {max_value}) and saved to {filename}.")
    print(f"Duplicates found: {duplicates}")

if __name__ == "__main__":
    main()

