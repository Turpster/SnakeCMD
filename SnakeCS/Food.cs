using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SnakeCS
{
    class Food : Entity
    {
        public Food(Location location, Vector vector, char model) : base(location, vector, model) {}
    }
}
