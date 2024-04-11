#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <memory>


class Tester
{
public:
    Tester(std::string _name) : name { _name } {}
    virtual ~Tester() = default;

    bool runAllTests();
    void addTestCase(bool result);
    std::string getName() const { return name; }
    size_t getNumTests() const { return testResults.size(); }
    void setVerbose(bool _verbose) { verbose = _verbose; }
    bool getVerbose() const { return verbose; }
    std::string getTestLog() const { return ss.str(); }

    virtual bool testAllProblems() = 0;
    virtual std::unique_ptr<Tester> clone() const = 0;

protected:
    Tester(const Tester& other)
    :   name    { other.name }
    ,   verbose { other.verbose } 
    {}

    std::stringstream ss;

private:
    std::vector<bool> testResults;
    std::string name;
    bool verbose { false };
};