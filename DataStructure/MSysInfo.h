#ifndef MSYSINFO_H
#define MSYSINFO_H

class MSysInfo{
public:
    ~MSysInfo();
    static MSysInfo* Instance();

    void Init();
    void Open();

    MSysInfo(const MSysInfo &rhs) = delete;
    MSysInfo& operator= (const MSysInfo &rhs) = delete;

protected:
    MSysInfo();
private:
    static MSysInfo *instance_;
};

#endif // MSYSINFO_H
