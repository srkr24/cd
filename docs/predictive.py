import pandas as pd
def is_accepted(predictive_table, input_string, start_symbol="E"):
    stack = ["$", start_symbol]
    input_string += "$"
    input_index = 0
    while True:
        stack_str = "".join(stack)
        input_str = input_string[input_index:]
        top_of_stack = stack[-1]
        input_symbol = input_string[input_index]
        action = ""

        if top_of_stack == "$" and input_symbol == "$":
            action = "accept"
            print(f"{stack_str}\t\t{input_str}\t\t{action}")
            break;

        if top_of_stack in predictive_table and input_symbol in predictive_table[top_of_stack]:
            production = predictive_table[top_of_stack][input_symbol]
            stack.pop()

            if production != "@":
                production_symbols = production.split(" ")
                stack.extend(reversed(production_symbols))
            action = f"{top_of_stack} -> {production}"

        elif top_of_stack == input_symbol:
            stack.pop()
            input_index += 1
            action = f"pop {input_symbol}"

        else:
            action = "reject"
            print(f"{stack_str}\t\t{input_str}\t\t{action}")
            break;
        print(f"{stack_str}\t\t{input_str}\t\t{action}")

predictive_table = {
    "E": {"(": "T E'", "i": "T E'"},
    "E'": {"+": "+ T E'", "$": "@"},
    "T": {"(": "F T'", "i": "F T'"},
    "T'": {"+": "@", "*": "* F T'", ")": "@", "$": "@"},
    "F": {"(": "( E )", "i": "i"}
}

print("the predictive parsing table is: ")
df = pd.DataFrame.from_dict(predictive_table, orient='index')
df.fillna('   ', inplace=True)
print(df)

input_string = input("enter input string (i.e. i+i*i): ")

is_accepted(predictive_table, input_string)