using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SnakeCS
{
    class Entity
    {
        public Location location;
        public Vector vector;
        readonly char model;

        public Entity(Location location, Vector vector, char model)
        {
            this.location = location;
            this.vector = vector;
            this.model = model;
        }

        public virtual void Tick()
        {
            this.location.x += this.vector.xv;
            this.location.y += this.vector.yv;
        }

        public virtual void Render(int x, int y)
        {
            if (x == this.location.x && y == this.location.y)
            {
                Console.Write(model);
            }
        }
    }
}
