#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

class StereoReceiver {
private:
    string manufacturer;
    string model;
    string serialNumber;
    int wattage;
    int numChannels;
    string band;
    double frequency;
    int volume;
    bool power;
    // Additional attributes
    string color;
    bool bluetoothEnabled;

public:
    // Constructor with exception handling
    StereoReceiver(const string& manuf, const string& mdl, const string& serial, int watts, int channels)
        : manufacturer(manuf), model(mdl), serialNumber(serial), wattage(watts), numChannels(channels) {
        if (manufacturer.empty() || model.empty() || serialNumber.empty()) {
            throw invalid_argument("Manufacturer, Model, or Serial Number not provided.");
        }
        if (wattage <= 0 || channels < 0) {
            throw invalid_argument("Inappropriate values for Wattage or Number of Channels.");
        }
        band = "AM";  // Default band
        frequency = 100.0;  // Default frequency
        volume = 5;  // Default volume
        power = false;  // Default power off
        // Initialize additional attributes
        color = "Black";
        bluetoothEnabled = false;
    }

    // Accessor/Get Methods
    string getManufacturer() const { return manufacturer; }
    string getModel() const { return model; }
    string getSerialNumber() const { return serialNumber; }
    int getWattage() const { return wattage; }
    int getNumChannels() const { return numChannels; }
    string getBand() const { return band; }
    double getFrequency() const { return frequency; }
    int getVolume() const { return volume; }
    bool getPower() const { return power; }
    string getColor() const { return color; }
    bool isBluetoothEnabled() const { return bluetoothEnabled; }

    // Mutator/Set Methods with exception handling
    void setPower(bool onOff) { power = onOff; }
    void setVolume(int vol) {
        if (vol < 0 || vol > 10) {
            throw invalid_argument("Invalid Value - Volume must be between 0 and 10.");
        }
        volume = vol;
    }
    void setBand(const string& newBand) {
        if (newBand != "AM" && newBand != "FM") {
            throw invalid_argument("Invalid Band - Use 'AM' or 'FM'.");
        }
        band = newBand;
    }
    void setFrequency(double freq) {
        if (freq < 88.0 || freq > 108.0) {
            throw invalid_argument("Invalid Frequency - Must be between 88.0 and 108.0.");
        }
        frequency = freq;
    }
    void setColor(const string& newColor) { color = newColor; }
    void setBluetooth(bool enabled) { bluetoothEnabled = enabled; }
};

int main() {
    string manuf, model, serial;
    int watts, channels;

    try {
        // Prompt user for information
        cout << "Enter manufacturer: ";
        getline(cin, manuf);
        if (manuf.empty()) {
            throw invalid_argument("Manufacturer not provided.");
        }
        cout << "Enter model: ";
        getline(cin, model);
        if (model.empty()) {
            throw invalid_argument("Model not provided.");
        }
        cout << "Enter serial number: ";
        getline(cin, serial);
        if (serial.empty()) {
            throw invalid_argument("Serial Number not provided.");
        }
        cout << "Enter wattage: ";
        cin >> watts;
        if (watts <= 0) {
            throw invalid_argument("Invalid Value - Wattage must be positive.");
        }
        cout << "Enter number of channels: ";
        cin >> channels;
        if (channels < 0) {
            throw invalid_argument("Invalid Value - Number of channels cannot be negative.");
        }

        // Create StereoReceiver object
        StereoReceiver receiver(manuf, model, serial, watts, channels);

        // Display information using Accessor Methods
        cout << "\nStereoReceiver Information:\n";
        cout << "Manufacturer: " << receiver.getManufacturer() << endl;
        cout << "Model: " << receiver.getModel() << endl;
        cout << "Serial Number: " << receiver.getSerialNumber() << endl;
        cout << "Wattage: " << receiver.getWattage() << endl;
        cout << "Number of Channels: " << receiver.getNumChannels() << endl;

        // Turn on the StereoReceiver
        receiver.setPower(true);

        // Allow user to change settings
        string newBand;
        double newFreq;
        int newVol;
        cout << "\nEnter new band (AM/FM): ";
        cin >> newBand;
        receiver.setBand(newBand);
        cout << "Enter new frequency: ";
        cin >> newFreq;
        receiver.setFrequency(newFreq);
        cout << "Enter new volume (0-10): ";
        cin >> newVol;
        receiver.setVolume(newVol);

        // Display settings
        cout << "\nStereoReceiver Settings:\n";
        cout << "Power: " << (receiver.getPower() ? "On" : "Off") << endl;
        cout << "Band: " << receiver.getBand() << endl;
        cout << "Frequency: " << receiver.getFrequency() << endl;
        cout << "Volume: " << receiver.getVolume() << endl;

        // Turn off the StereoReceiver
        receiver.setPower(false);
    } catch (const exception& e) {
        cerr << "Exception: " << e.what() << endl;
        return 1; // Return error code
    }

    return 0;
}
