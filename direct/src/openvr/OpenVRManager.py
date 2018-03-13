from direct.showbase.DirectObject import DirectObject
try:
    from panda3d.openvr import *
    has_openvr = True
except:
    has_openvr = False

if not has_openvr:
    raise Exception('This feature is unsupported. Please recompile Panda3D with OpenVR support')

class OpenVRManager(DirectObject):
    """
    Manages the required componets to run Panda3d with OpenVR
    """

    def __init__(self):
        DirectObject.__init__(self)

        self.vr_system = OpenVRSystem.get_global_ptr()
        self._vr_devices = []

        self._data_loop = None

    @property
    def initialized(self):
        """
        Returns true if the OpenVRSystem is initialized
        """
        return self.vr_system.initialized

    @property
    def vr_devices(self):
        """
        Returns a list of currently connected OpenVR devices
        """
        return self._vr_devices

    def initialize(self):
        """
        Initializes the OpenVR system
        """
        response = self.vr_system.init()

        # Start the data loop if the initialization was succesfully completed

        if response == 0:
            self._data_loop = base.taskMgr.add(self.__dataLoop, 'vr-dataLoop')

        self.accept('connect-device', self.__connect_vr_device)
        self.accept('disconnect-device', self.__disconnect_vr_device)

        return response

    def shutdown(self):
        """
        Shuts down the OpenVR system
        """

        if not self.initialized:
            return

        self.vr_system.shutdown()
        base.taskMgr.remove(self._data_loop)

        self.ignoreAll()

    def __dataLoop(self, task):
        """
        Processes the repeating loop tasks to manage a OpenVR setup
        """

        # Verify the OpenVRSystem is ready
        if not self.initialized:
            return

        self.vr_system.update()
        
        return task.cont

    def __connect_vr_device(self, device):
        """
        Registers a newly connected OpenVR device
        """

        if isinstance(device, OpenVRDevice) and not device in self._vr_devices:
            self._vr_devices.append(device)

        messenger.send('connect-vr-device', [device])

    def __disconnect_vr_device(self, device):
        """
        Unregisters a previously connected OpenVR device
        """

        if isinstance(device, OpenVRDevice) and device in self._vr_devices:
            self._vr_devices.remove(device)

        messenger.send('disconnect-vr-device', [device])
        

