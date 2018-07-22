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
            if (location.x + vector.xv > 0 && location.x + vector.xv < Program.WIDTH)
            {
                location.x += vector.xv;
            }
            else
            { 
                /*
                 * Make better exit method
                 */
            }
            if (location.y + vector.yv > 0 && location.y + vector.yv < Program.HEIGHT)
            {
                location.y += vector.yv;
            }
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
