#pragma once

#include <memory>
#include <string>


class Solution
{
public:
    Solution(const std::string& _name, const std::string& _description)
    :   name        { _name }
    ,   description { _description }
    {}

    virtual ~Solution() = default;
    virtual std::unique_ptr<Solution> clone() const = 0;

    std::string getName() const { return name; }
    std::string getDescription() const { return description; }

private:
    std::string name;
    std::string description;
};