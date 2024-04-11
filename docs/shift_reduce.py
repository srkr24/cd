def shift_reduce_parser(input_string):
    stack = ['$']  # Initial stack with end marker
    input_string += '$'  # Add end marker to input string
    i = 0

    print("Stack\t\tInput\t\tAction")

    while True:
        stack_str = "".join(stack)
        input_str = input_string[i:]
        action = ""

        if len(stack) == 2 and stack[0] == '$' and stack[1] == 'E' and input_string[i] == '$':
            action = "String accepted!"
            print(f"{stack_str}\t\t{input_str}\t\t{action}")
            break
        if stack[-1] == '4':
            stack.pop()
            stack.append('E')
            action = "Reduce using E -> 4"
        elif len(stack) >= 3 and stack[-1] == '3' and stack[-2] == 'E' and stack[-3] == '3':
            stack = stack[:-3] # Pop 3, E, 3
            stack.append('E')
            action = "Reduce using E -> 3E3"
        elif len(stack) >= 3 and stack[-1] == '2' and stack[-2] == 'E' and stack[-3] == '2':
            stack = stack[:-3] # Pop 2, E, 2
            stack.append('E')
            action = "Reduce using E -> 2E2"
        elif input_string[i] == '$':
            action = "String rejected!"
            print(f"{stack_str}\t\t{input_str}\t\t{action}")
            break
        else:
            stack.append(input_string[i])
            i += 1
            action = "Shift"

        print(f"{stack_str}\t\t{input_str}\t\t{action}")

# Test the parser
input_string = "23432"
shift_reduce_parser(input_string)