--[[
--- Send plot data to ra
module "plot"
]]--

--[[***********************************************************************
*   Copyright 2014 Michael Eischer                                        *
*   Robotics Erlangen e.V.                                                *
*   http://www.robotics-erlangen.de/                                      *
*   info@robotics-erlangen.de                                             *
*                                                                         *
*   This program is free software: you can redistribute it and/or modify  *
*   it under the terms of the GNU General Public License as published by  *
*   the Free Software Foundation, either version 3 of the License, or     *
*   any later version.                                                    *
*                                                                         *
*   This program is distributed in the hope that it will be useful,       *
*   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
*   GNU General Public License for more details.                          *
*                                                                         *
*   You should have received a copy of the GNU General Public License     *
*   along with this program.  If not, see <http://www.gnu.org/licenses/>. *
*************************************************************************]]

local plot = {}
local amun = amun

--- Add data to a plot. Value is used to create a point at the current time
-- @name addPlot
-- @param name string - Plot name, seperated layers by '.'
-- @param value number - value for data point
function plot.addPlot(name, value)
	amun.addPlot(name, value)
end

return plot