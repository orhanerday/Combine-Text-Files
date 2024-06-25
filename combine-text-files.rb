class CombineTextFiles < Formula
    desc "Combine text files in a directory into a single file"
    homepage "https://github.com/orhanerday/combine-text-files"
    url "https://github.com/orhanerday/combine-text-files/archive/refs/tags/v1.0.tar.gz"
    sha256 "1f76898e1b2beff6404b4106a00277e54e4cde85c4d60c9d006e8579e3d98c45"
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