import os

def is_text_file(file_path):
    """
    Determines if a file is a text file.
    """
    try:
        with open(file_path, 'r') as file:
            file.read()
        return True
    except:
        return False

def read_and_append_files(input_folder, output_file):
    """
    Reads all text files in the input_folder and its subfolders,
    and appends their content to the output_file with delimiters.
    """
    with open(output_file, 'w') as out_file:
        for root, _, files in os.walk(input_folder):
            for file in files:
                file_path = os.path.join(root, file)
                if is_text_file(file_path):
                    with open(file_path, 'r') as in_file:
                        content = in_file.read()
                        out_file.write(f"File: {file}\n")
                        out_file.write("------\n")
                        out_file.write(content)
                        out_file.write("\n------\n\n")

if __name__ == "__main__":
    input_folder = "Project"  # Change this to your input folder
    output_file = "single_file.txt"
    read_and_append_files(input_folder, output_file)
    print(f"All text files from '{input_folder}' have been combined into '{output_file}'.")