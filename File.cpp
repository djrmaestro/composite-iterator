#include "File.h"
#include <ostream>
using namespace std;

void File::print(ostream& ostr) const
{
    ostr << getName();
}
