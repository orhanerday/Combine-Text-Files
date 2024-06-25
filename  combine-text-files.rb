class CombineTextFiles < Formula
    desc "Combine text files in a directory into a single file"
    homepage "https://github.com/orhanerday/combine-text-files"
    url "https://github.com/orhanerday/combine-text-files/archive/refs/tags/v1.0.tar.gz"
    sha256 "your_generated_sha256_checksum"
    license "MIT"
  
    depends_on "python@3.9"
  
    def install
      bin.install "combine_text_files.py"
    end
  
    test do
      (testpath/"test.py").write <<~EOS
        print("test")
      EOS
      system "#{bin}/combine_text_files.py"
    end
  end