template <typename T>
class BitStream {
private:
    vector<T> array;

    size_t readPos_ = 0;
    size_t writePos_ = 0;

public:
    BitStream() = default;

    BitStream(const T* data, size_t lenght) {
        Write(data, lenght);
        ResetRead();
    }

    ~BitStream() {
        readPos_ = 0;
        writePos_ = 0;

        array.clear();
    }

    void Write(const T* data, size_t lenght) {
        if (lenght == 0) return;

        const T* value = static_cast<const T*>(data);

        if (writePos_ + lenght > array.size()) {
            array.resize(writePos_ + lenght);
        }

        memcpy(array.data() + writePos_, value, lenght);
        writePos_ += lenght;
    }

    void Read(T* out, size_t lenght) {
        if (!CanRead(lenght)) {
            printf("Out of bounds!\n");
            return;
        }
        
        memcpy(out, array.data() + readPos_, lenght);
        readPos_ += lenght;
    }

    const T* GetData() {
        return array.data();
    }

    size_t GetLenght() const {
        return array.size();
    }

    void ResetRead() {
        readPos_ = 0;
    }

    void ResetWrite() {
        writePos_ = 0;
    }

    bool CanRead(size_t lenght) {
        if (readPos_ + lenght > array.size()) return false;

        return true;
    }
};
