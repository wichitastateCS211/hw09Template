// Name:
// WSUID:
// HW: 09
// Description: Implement a class to represent a zip code

// Includes go here

class Zipcode {
public:
    Zipcode() = default;
    Zipcode(std::string s);
    std::array<int, 5> get_digits();
    std::string        get_string();
    std::string        get_POSTNET();
    void               set_zipcode(std::string zip);
    void               print_barcode(std::ostream& sout = std::cout);

private:
    // Typename m_zip  // The lowest residential zip code is 00601 in Adjuntas, PR.
                       // This must be your default value.

    // NOTE: Bogus values passed to the parameterized constructor or
    // set_zipcode() will result in the zip code being set to 00601. Bogus
    // values are too short, too long, or a 5 character string that is not all
    // digits.
};

// Zipcode Functions are implemented here.
