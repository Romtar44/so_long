#ifndef SL_DEFINITIONS_H
# define SL_DEFINITIONS_H

/*****************************************************************
 * EVENT DEFINITIONS
 *****************************************************************/

/* Input Event Masks. Used as event-mask window attribute and as arguments
   to Grab requests.  Not to be confused with event names.  */

# define NoEventMask				0L
# define KeyPressMask				(1L<<0)
# define KeyReleaseMask				(1L<<1)
# define ButtonPressMask			(1L<<2)
# define ButtonReleaseMask			(1L<<3)
# define EnterWindowMask			(1L<<4)
# define LeaveWindowMask			(1L<<5)
# define PointerMotionMask			(1L<<6)
# define PointerMotionHintMask		(1L<<7)
# define Button1MotionMask			(1L<<8)
# define Button2MotionMask			(1L<<9)
# define Button3MotionMask			(1L<<10)
# define Button4MotionMask			(1L<<11)
# define Button5MotionMask			(1L<<12)
# define ButtonMotionMask			(1L<<13)
# define KeymapStateMask			(1L<<14)
# define ExposureMask				(1L<<15)
# define VisibilityChangeMask		(1L<<16)
# define StructureNotifyMask		(1L<<17)
# define ResizeRedirectMask			(1L<<18)
# define SubstructureNotifyMask		(1L<<19)
# define SubstructureRedirectMask	(1L<<20)
# define FocusChangeMask			(1L<<21)
# define PropertyChangeMask			(1L<<22)
# define ColormapChangeMask			(1L<<23)
# define OwnerGrabButtonMask		(1L<<24)

/* Event names.  Used in "type" field in XEvent structures.  Not to be
confused with event masks above.  They start from 2 because 0 and 1
are reserved in the protocol for errors and replies. */

# define KeyPress			2
# define KeyRelease			3
# define ButtonPress		4
# define ButtonRelease		5
# define MotionNotify		6
# define EnterNotify		7
# define LeaveNotify		8
# define FocusIn			9
# define FocusOut			10
# define KeymapNotify		11
# define Expose				12
# define GraphicsExpose		13
# define NoExpose			14
# define VisibilityNotify	15
# define CreateNotify		16
# define DestroyNotify		17
# define UnmapNotify		18
# define MapNotify			19
# define MapRequest			20
# define ReparentNotify		21
# define ConfigureNotify	22
# define ConfigureRequest	23
# define GravityNotify		24
# define ResizeRequest		25
# define CirculateNotify	26
# define CirculateRequest	27
# define PropertyNotify		28
# define SelectionClear		29
# define SelectionRequest	30
# define SelectionNotify	31
# define ColormapNotify		32
# define ClientMessage		33
# define MappingNotify		34
# define GenericEvent		35
# define LASTEvent			36

# define FRAMERATE 4500
# define E_FRAMERATE 9000
# define DASH_SIZE 2
# define ENEMY_NUMBER 2
# define ENEMY_SPEED 5000
# define V_RANGE 5
# define DAMAGE 25
# define P_HP 1000

enum e_view
{
	EV_LEFT,
	EV_RIGHT,
};

enum e_keycodes
{
	EK_ESC = 65307,
	EK_Z = 122,
	EK_Q = 113,
	EK_S = 115,
	EK_D = 100,
	EK_E = 101,
	EK_A = 97,
	EK_TR = 32,
};

enum e_error
{
	EE_NONE = 0,
	EE_INVARG = 1,
	EE_INVMAP = 2,
	EE_INVMAL = 3,
	EE_INVNAM = 4,
	EE_INVIMG = 5,
	EE_GG = 6,
};

enum e_texture_indexes
{
	ETI_GROUND = 0,
	ETI_WALL = 1,
	ETI_ITEM = 2,
	ETI_EXIT = 3,
	ETI_PLAYER1 = 4,
	ETI_PLAYER2 = 5,
	ETI_PLAYER3 = 6,
	ETI_PLAYER4 = 7,
};

enum e_anim_indexes
{
	EAI_FRAME1,
	EAI_FRAME2,
	EAI_FRAME3,
	EAI_FRAME4,
	EAI_FRAME5,
	EAI_FRAME6,
	EAI_FRAME7,
	EAI_FRAME8,
	EAI_FRAME9,
	EAI_FRAME10,
	EAI_FRAME11,
	EAI_FRAME12,
	EAI_FRAME13,
	EAI_FRAME14,
	EAI_FRAME15,
};
#endif
