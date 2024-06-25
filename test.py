import os
import unittest
import tempfile
import shutil
from combine_text_files import read_and_append_files

class TestCombineTextFiles(unittest.TestCase):
    def setUp(self):
        # Create a temporary directory
        self.test_dir = tempfile.mkdtemp()

        # Create sample text files
        self.file1_path = os.path.join(self.test_dir, "file1.txt")
        self.file2_path = os.path.join(self.test_dir, "subdir", "file2.txt")

        os.makedirs(os.path.dirname(self.file2_path), exist_ok=True)

        with open(self.file1_path, "w") as f:
            f.write("Content of file1")

        with open(self.file2_path, "w") as f:
            f.write("Content of file2")

        # Output file path
        self.output_file_path = os.path.join(self.test_dir, "single_file.txt")

    def tearDown(self):
        # Remove the temporary directory after the test
        shutil.rmtree(self.test_dir)

    def test_combine_files(self):
        # Run the combine_text_files script
        read_and_append_files(self.test_dir, self.output_file_path)

        # Check the content of the output file
        with open(self.output_file_path, "r") as f:
            content = f.read()

        expected_content = (
            "File: file1.txt\n"
            "------\n"
            "Content of file1\n"
            "------\n\n"
            "File: file2.txt\n"
            "------\n"
            "Content of file2\n"
            "------\n\n"
        )

        self.assertEqual(content, expected_content)

if __name__ == "__main__":
    unittest.main()