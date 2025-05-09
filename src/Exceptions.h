#include <fstream>

class GameException : public std::exception {
 public:
  virtual const char* what() const noexcept override {
    return "Generic game exception";
  }
};

class TextureLoadException : public GameException {
  std::string filename;
  std::string reason;

 public:
  TextureLoadException(const std::string& file, const std::string& why)
      : filename(file), reason(why) {}

  const char* what() const noexcept override {
    static std::string message;
    message = "Texture error [" + filename + "]: " + reason;
    return message.c_str();
  }

  const std::string& getFilename() const { return filename; }
  const std::string& getReason() const { return reason; }
};

class HighScoreException : public GameException {
  std::string filename;
  int corruptValue;

 public:
  enum class ErrorType { FileNotFound, InvalidFormat, CorruptData };

  HighScoreException(ErrorType type, const std::string& file, int badValue = -1)
      : filename(file), corruptValue(badValue) {
    switch (type) {
      case ErrorType::FileNotFound:
        reason = "High score file not found: " + filename;
        break;
      case ErrorType::InvalidFormat:
        reason = "Invalid file format in: " + filename;
        break;
      case ErrorType::CorruptData:
        reason =
            "Corrupt data (" + std::to_string(badValue) + ") in: " + filename;
        break;
    }
  }

  const char* what() const noexcept override { return reason.c_str(); }

  void createDefaultFile() const {
    std::ofstream newFile(filename);
    newFile << "0";  // Default high score
  }

 private:
  std::string reason;
};

