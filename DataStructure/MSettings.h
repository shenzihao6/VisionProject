#ifndef MSETTINGS_H
#define MSETTINGS_H

class MSettings{
public:
    MSettings();
    ~MSettings();
    MSettings(const MSettings &rhs);
    MSettings& operator=(const MSettings &rhs);

    bool operator == (const MSettings &rhs);
    bool operator !=(const MSettings &rhs);

private:

};

#endif // MSETTINGS_H
